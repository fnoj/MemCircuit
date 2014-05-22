#bin/bash
clear
echo "Verifying Dependencies...."
DIR="`pwd`"
BIN="/usr/bin"
LOCAL="/usr/share/memcircuit"
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
	    echo "For continue the installation, you need to be root user!"
	    sudo mkdir $LOCAL
	    sudo cp -r icons/* $LOCAL
	    sudo chmod ugo+xwr -R $LOCAL
	    make
	    make clean	   
	    echo " "
	    echo " "
	    echo "Compiling Successful!"
	    echo " "
	    echo "Creating link!"
	    sudo ln -d -s -f $DIR/MemCircuit $BIN/memcircuit
	    sudo chmod u+xwr $BIN/memcircuit
	    echo "Installation Successful!"
	    echo "For run MemCircuit from terminal execute:"
	    echo "$ memcircuit"
	fi
    fi
fi