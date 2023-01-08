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
    defines = [
        "VERSION=\\\"0.6+bazel\\\"",
    ],
    linkopts = [
        # Link from local libraries
        "-L/usr/lib/",
        "-lX11",
        "-lXft",  # libxft-dev
        "-lfontconfig",
    ],
    deps = [
        ":arg",
        ":config",
    ],
)

cc_binary(
    name = "xembed",
    srcs = ["xembed.c"],
)
