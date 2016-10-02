cmst
====

QT GUI for Connman with system tray icon.

The program provides graphical user interface to control the connman daemon.  The connman daemon
must be started as you normally would, this program just interfaces with that daemon. You can see
what technologies and services connman has found, and for wifi services an agent is registered to
assist in obtaining the information from you necessary to logon the wifi service.

As of 2016.01.26 support for VPN connections (create, edit, delete, connect and disconnect) has been added.  It is also possible to import an OpenVPN .opvn file.  The import function will scan the .opvn file extracting and saving keys and certificates, and then place the proper lines into the provisioning editor.

The program requires that connman be installed and running.  The program depends on QT5, but only the base package. 

The [Wiki](https://github.com/andrew-bibb/cmst/wiki) has been started and announcements, news, and other information can be found there.

[Screen shots:](https://github.com/andrew-bibb/cmst/wiki/Screenshots) are now included in the Wiki

There is a PKGBUILD for this project in the Arch Linux AUR.

The Provisioning Editor and VPN Provisioning Editor both register a root helper to assist in editing files in directories owned by root (/var/lib/connman and /var/lib/connman-vpn).  In order to use the root helper you must be a member of the proper group, and this group varies by distribution.  To get the proper file for your distribution you need to provide it on the qmake line. Currently there are files for Arch Linux, Slackware, and Debian.  If you are on Arch you don't actually need to supply the distro as that is the default if one is not supplied, but it is not wrong to do so. 

If you are not on Arch or don't choose to use the AUR download the release and extract the files.  Then run:

    qmake DISTRO=xxxx
    make
    make install (as root)

Where xxx is one of [arch, debian, slackware). Distro names are case sensitive.

Development Status:  The program is really kind of feature complete as of October 2016.  There are several ConnMan features we've not implemented but they are all currently marked experimental.  As a rule we've tried to avoid these, although we have made exceptions.  I still subscribe to the ConnMan developer mailing list to keep an eye on what is happening there and will update this program accordingly.  If there is a feature you need or want, either a ConnMan feature or in the CMST UI, please do not hesitate to open up an issue about it.     
