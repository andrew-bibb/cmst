#	Build distro

# define a build distro
isEmpty( DISTRO ) {
	DISTRO = arch
}

BUILD_DISTRO = $$DISTRO

# define a libpath
LIB_PATH = $$(USE_LIBPATH)
isEmpty ( LIB_PATH ) {
	LIB_PATH = "/usr/lib/cmst"
} 

