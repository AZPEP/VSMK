# generated by configure / remove this line to disable regeneration
prefix="/usr/local"
exec_prefix="${prefix}"
bindir="${exec_prefix}/bin"
libdir="/home/azpep/桌面/i686-elf-toolkit/gcc-12.1.0/build/isl/.libs"
datarootdir="${prefix}/share"
datadir="${datarootdir}"
sysconfdir="${prefix}/etc"
includedir="/home/azpep/桌面/i686-elf-toolkit/gcc-12.1.0/build/isl/../../isl/include"
package="isl"
suffix=""

for option; do case "$option" in --list-all|--name) echo  "isl"
;; --help) pkg-config --help ; echo Buildscript Of "isl Library"
;; --modversion|--version) echo "0.24"
;; --requires) echo : ""
;; --libs) echo -L${libdir} "" "-lisl /home/azpep/桌面/i686-elf-toolkit/gcc-12.1.0/build/./gmp/libgmp.la"
       :
;; --cflags) echo -I${includedir} "-I/home/azpep/桌面/i686-elf-toolkit/gcc-12.1.0/build/gmp/../../gmp -I/home/azpep/桌面/i686-elf-toolkit/gcc-12.1.0/build/./gmp"
       :
;; --variable=*) eval echo '$'`echo $option | sed -e 's/.*=//'`
;; --uninstalled) exit 0 
;; *) ;; esac done