mkdir ~/week1/root
date
sleep 3
mkdir ~/week1/home
date
sleep 3
touch ~/week1/root/root.txt
date
sleep 3
touch ~/week1/home/home.txt
ls -tr / > ~/week1/root/root.txt
ls -tr ~/ > ~/week1/home/home.txt
ls ~/week1/root 
cat ~/week1/root/root.txt
ls ~/week1/home 
cat ~/week1/home/home.txt

