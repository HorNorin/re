# -*- ruby -*-

require "rubygems"
require "hoe"
require "rake/extensiontask"

# Hoe.plugin :compiler
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
# Hoe.plugin :minitest
# Hoe.plugin :racc
# Hoe.plugin :rcov
# Hoe.plugin :rdoc

Hoe.spec "re" do
  developer 'Norin', 'norin.hor@gmail.com'
  Rake::ExtensionTask.new('re', spec) do |ext|
    ext.name    = 're'
    ext.ext_dir = File.join('ext', 're')
    ext.lib_dir = File.join('lib', 're')
  end
end

# vim: syntax=ruby
