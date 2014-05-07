#bin/bash
clear
echo "Verifying Dependencies...."
DIR="/usr/share/memcircuit"
BIN="/usr/bin"
ans="`find /usr/bin/ -iname root`"    
if [ "${ans:-NULL}" = "NULL" ]; 
then
    echo "You need install ROOT framework!"
else
    echo "ROOT is Installed!"
    ans="`dpkg -l | grep octave3.2`"
    if [ "${ans:-NULL}" = "NULL" ]; 
    then
	echo "You need install Octave3.2 package!"
    else
	echo "Octave3.2 is Installed!"
        ans="`dpkg -l | grep xutils-dev`"
	if [ "${ans:-NULL}" = "NULL" ]; 
	then
	    echo "You need install xutils-dev package!"
	else
	    echo "xutils-dev is Installed!"
	    echo " "
	    echo " "
	    echo "Verifying Successful!"
	    echo " "
	    echo "Compiling ..."
	    make
	    make clean	   
	    sudo mkdir -p $DIR
	    sudo cp  ../MemCircuit*/ $DIR
	    echo " "
	    echo " "
	    echo "Compiling Successful!"
	    echo " "
	    echo "For you finish installation, you need to be root user!"
	    sudo ln -s $DIR/MemCircuit /usr/bin/memcircuit
	    echo "Installation Successful!"
	    echo "For run MemCircuit from terminal execute:"
	    echo "$ memcircuit"
	fi
    fi
fi