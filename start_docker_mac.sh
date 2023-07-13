
docker build -t eufs_sim .
xhost + 
sudo docker run -it --rm -v ~/.Xauthority:/root/.Xauthority --platform linux/amd64 --privileged --net=host -e DISPLAY=$DISPLAY eufs_sim:latest ./start_simulator.sh