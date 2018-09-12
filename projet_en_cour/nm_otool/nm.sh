#!/bin/bash
./ft_nm $* > toto1
nm $* > toto2
diff toto1 toto2
