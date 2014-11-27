# define a build distro
isEmpty( DISTRO ) {
	DISTRO = arch
}
CMST_BUILD_DISTRO = $$DISTRO

# define a path for user libraries (the roothelper program)
CMST_LIB_PATH = $$(USE_LIBPATH)
isEmpty ( CMST_LIB_PATH ) {
	CMST_LIB_PATH = "/usr/lib/cmst"
} 

# define a path for the man page
CMST_DOC_PATH = $$(USE_MANPATH)
isEmpty ( CMST_DOC_PATH ) {
	CMST_DOC_PATH = "/usr/share/man/man1"
}
