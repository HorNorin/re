#include <ruby.h>
#include <git2.h>

typedef struct repos_data {
    char *path;
} repos_data;

static void repos_dealloc(repos_data *data)
{
    free(data);
}

static VALUE repos_alloc(VALUE klass)
{
    repos_data *data = NULL;
    data = malloc(sizeof(repos_data));
    if (!data) {
        rb_raise(rb_eRuntimeError, "can't allocate repository data");
    }

    return Data_Wrap_Struct(klass, NULL, repos_dealloc, data);
}

static VALUE repos_init(VALUE self, VALUE path)
{
    repos_data *data = NULL;
    Data_Get_Struct(self, repos_data, data);

    data->path = StringValueCStr(path);
    return self;
}

static VALUE repos_clone(VALUE self, VALUE url)
{
    int error;
    repos_data *data = NULL;
    git_repository *repo = NULL;

    Data_Get_Struct(self, repos_data, data);

    error = git_clone(&repo, StringValueCStr(url), data->path, NULL);
    if (error != 0) {
        const git_error *e;
        e = giterr_last();
        rb_raise(rb_eRuntimeError, "error: %s", e->message);
    }

    return Qnil;
}

void Init_re()
{
    VALUE re;
    VALUE repos;

    git_libgit2_init();

    re    = rb_define_module("Re");
    repos = rb_define_class_under(re, "Repository", rb_cObject);

    rb_define_alloc_func(repos, repos_alloc);
    rb_define_method(repos, "initialize", repos_init, 1);
    rb_define_method(repos, "clone", repos_clone, 1);
}
