gcc -o tcpserver tcpserver.c -I.
./tcpserver --bufsize 1024 --serv_port 200001
#./tcpclient --bufsize 1024 --addr 127.0.0.1 --message pls,work --serv_port 200001