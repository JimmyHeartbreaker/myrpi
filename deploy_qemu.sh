echo "filename: $1";
projectName=$(basename $1);
echo $1/build/$projectName
ssh-keygen -f "~/.ssh/known_hosts" -R "10.0.2.17"
scp  -o StrictHostKeyChecking=no -r $1/build/Target/$projectName root@10.0.2.17:/usr/bin/ 
scp  -o StrictHostKeyChecking=no -r $1/build/Target/TestProgram root@10.0.2.17:/usr/bin/ 
#read -p "waiting for key input"