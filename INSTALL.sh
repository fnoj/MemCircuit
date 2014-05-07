#bin/bash
clear
echo "Verifying Dependencies...."
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
	echo "Octave3.2 is installed"
	
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
	echo "For install, you need to be root user!"
	sudo sudo cp MemCircuit /usr/bin/memcircuit
	sudo chmod u+x /usr/bin/memcircuit 
	echo " "
	echo " "
	echo "Installation Successful!"
	echo "For run SCMC execute from terminal:"
	echo "$ memcircuit"
    fi
fi