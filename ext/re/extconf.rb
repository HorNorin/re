require 'mkmf'

LIBS    = RbConfig::CONFIG['libdir']
HEADERS = RbConfig::CONFIG['includedir']

HEADER_DIRS = [
  HEADERS,
  '/usr/include',
  '/usr/local/include',
]

LIB_DIRS = [
  LIBS,
  '/usr/lib',
  '/usr/local/lib'
]

$LDFLAGS << ' ' + `pkg-config --libs libgit2`
$CFLAGS << ' ' + `pkg-config --cflags libgit2`

dir_config('re', HEADER_DIRS, LIB_DIRS)
create_makefile('re')
