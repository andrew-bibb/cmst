#	Build distro

# define a build distro
isEmpty( DISTRO ) {
	DISTRO = arch
}

BUILD_DISTRO = $$DISTRO
