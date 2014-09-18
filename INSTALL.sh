#bin/bash
clear
echo "Verifying Dependencies...."
DIR="`pwd`"
BIN="/usr/bin"
LOCAL="/usr/share/memcircuit"
ans="find /usr/bin/ -iname root*"    
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
#Create LOCAL FILES
	    sudo mkdir $LOCAL
	    sudo cp -r icons/* $LOCAL
	    sudo cp -r inc/* $LOCAL
	    sudo cp -r src/* $LOCAL
	    sudo cp -r MemCircuit.cxx $LOCAL
	    echo "Create Local Files!"
	    make
	    make clean	   
	    echo " "
	    echo " "
	    echo "Compiling Successful!"
	    echo " "
	    echo "Creating link!"
	    sudo cp -r $DIR/MemCircuit $LOCAL/memcircuit
	    sudo ln -d -s -f $LOCAL/memcircuit $BIN/memcircuit
#Add Permisions 	    
	    sudo chmod ugo+xwr -R $LOCAL
	    sudo chmod u+xwr $BIN/memcircuit
	    echo "Installation Successful!"
	    echo "For run MemCircuit from terminal execute:"
	    echo "$ memcircuit"
	fi
    fi
fi