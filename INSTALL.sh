#bin/bash
clear
echo "Verifying Dependencies...."
DIR="`pwd`"
BIN="/usr/bin"
ans="$ROOTSYS"    
if [ "${ans:-NULL}" = "NULL" ]; 
then
    echo "You need install ROOT framework!"
else
    echo "ROOT is Installed!"
    ans="`dpkg -l | grep octave`"
    if [ "${ans:-NULL}" = "NULL" ]; 
    then
	echo "You need install Octave package!"
	echo "For install execute:"
	echo "$sudo apt-get install octave"
    else
	echo "Octave is Installed!"
        ans="`dpkg -l | grep xutils-dev`"
	if [ "${ans:-NULL}" = "NULL" ]; 
	then
	    echo "You need install xutils-dev package!"
	    echo "For install execute:"
	    echo "$sudo apt-get install xutils-dev"
	else
	    echo "xutils-dev is Installed!"
	    echo " "
	    echo " "
	    echo "Verifying Successful!"
	    echo " "
	    echo "Compiling ..."
	    make
	    make clean	   
	    echo " "
	    echo " "
	    echo "Compiling Successful!"
	    echo " "
	    echo "For you finish installation, you need to be root user!"
	    echo "Creating link!"
	    sudo ln -f -s $DIR/MemCircuit /usr/bin/memcircuit
	    echo "Installation Successful!"
	    echo "For run MemCircuit from terminal execute:"
	    echo "$ memcircuit"
	fi
    fi
fi