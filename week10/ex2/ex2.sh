mkdir ../week01
echo "Anas" > ../week01/file.txt
mkdir ../week10
link ../week01/file.txt _ex2.txt
ls -i ../week01/file.txt
find -inum 548557
find -inum 548557 -exec rm {} \;
find -inum 548557
