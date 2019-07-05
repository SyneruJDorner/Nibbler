#Install Homebrew
which -s brew
if [[ $? != 0 ]] ; then
   sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
else
   brew update
fi