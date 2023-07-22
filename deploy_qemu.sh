echo "filename: $1";
projectName=$(basename $1);
echo $projectName
echo $1/build/$projectName
ssh-keygen -f "/home/jameshardaker/.ssh/known_hosts" -R "192.168.7.2"
scp  -o StrictHostKeyChecking=no -r $1/build/Default/$projectName root@192.168.7.2:/usr/bin/ 
read -p "waiting for key input"