# Maintainer: Gabriel Jensen
pkgname=u8c
pkgver=1.0.0
pkgrel=1
pkgdesc="C library for encoding, decoding, and printing UTF-8 bytes."
arch=("any")
url="https://mandelbrot.dk/delta/u8c"
license=("AGPL3")
makedepends=("git")
source=("git+https://mandelbrot.dk/delta/u8c.git")
sha512sums=("SKIP")
build() {
	cd "$srcdir/$pkgname"
	make -j$(nproc)
}
package() {
	cd "$srcdir/$pkgname"
	make DESTDIR="$pkgdir/usr" install
}
