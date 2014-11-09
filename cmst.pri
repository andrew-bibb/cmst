#	Build distro

# define a build distro
isEmpty( DISTRO ) {
	DISTRO = arch
}

CMST_BUILD_DISTRO = $$DISTRO

# define a libpath
CMST_LIB_PATH = $$(USE_LIBPATH)
isEmpty ( CMST_LIB_PATH ) {
	CMST_LIB_PATH = "/usr/lib/cmst"
} 

