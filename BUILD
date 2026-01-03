filegroup(
  name = "path_bins",
  srcs = [
    ":tabbed",
  ],
  visibility = ["//visibility:public"],
)

cc_library(
  name = "config",
  hdrs = ["config.h"],
)

cc_library(
  name = "arg",
  hdrs = ["arg.h"],
)

cc_binary(
  name = "tabbed",
  srcs = ["tabbed.c"],
  deps = [
    ":arg",
    ":config",
  ],
  defines = [
    "VERSION=\\\"0.9+bazel\\\"",
  ],
  copts = [
    # This binary depends on libxft-dev, and freetype2
    "-I/usr/include/freetype2",
    # Disable a bunch of the regular cc build options because this library is
    # sourced externally and doesn't comply with the strict requirements
    # imposed on the rest of the repo.
    "-Wno-cast-qual",
    "-Wno-discarded-qualifiers",
    "-Wno-format-truncation",
    "-Wno-sign-compare",
    "-Wno-unused-function",
  ],
  linkopts = [
    # Link from local libraries
    "-L/usr/lib/",
    "-lX11",
    "-lXft", # libxft-dev
    "-lfontconfig",
  ],
)

cc_binary(
  name = "xembed",
  srcs = ["xembed.c"],
)
