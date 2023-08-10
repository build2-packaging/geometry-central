import pkgs = {*/ -upstream/ -*-tests/ -*-examples/}
import tests = {*-tests/ *-examples/}

./: $pkgs
./: $tests: install = false
