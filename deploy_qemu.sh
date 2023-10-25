echo "filename: $1";
projectName=$(basename $1);
echo $1/build/Target/$projectName
ssh-keygen -R "127.0.0.1"
scp -o StrictHostKeyChecking=no  -r $1/build/Target/${projectName} root@127.0.0.1:/usr/bin/ 
scp -o StrictHostKeyChecking=no  -r $1/build/Target/${projectName}_Tests root@127.0.0.1:/usr/bin/ 
#read -p "waiting for key input"

