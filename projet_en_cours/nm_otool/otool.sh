#!/bin/bash
./ft_otool $* > toto1
otool -t $* > toto2
diff toto1 toto2
