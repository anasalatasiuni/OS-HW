mkdir ~/week1 
cd ~/week1
ls /usr/bin | sort --ignore-case -r  | grep gcc | tail --lines=5 > ~/week1/ex1.txt
