## How to test

```bash
mkdir -p t
cd t
cmake ..
make dev
./timedrun <num_run> <prog> [arg .. arg]
```

### Sample output

```bash
# make dev                                                                                                                                               
[100%] Building C object CMakeFiles/timedrun.dir/timedrun.c.o                                                                                                                                           
Linking C executable timedrun                                                                                                                                                                           
[100%] Built target timedrun                                                                                                                                                                            
Running tests...                                                                                                                                                                                        
Test project /home/kikitux/Dropbox/am/Git/kikitux/timedrun/t                                                                                                                                            
    Start 1: true1                                                                                                                                                                                      
1/6 Test #1: true1 ............................   Passed    0.00 sec                                                                                                                                    
    Start 2: true2                                                                                                                                                                                      
2/6 Test #2: true2 ............................   Passed    0.00 sec                                                                                                                                    
    Start 3: echo                                                                                                                                                                                       
3/6 Test #3: echo .............................   Passed    0.00 sec                                                                                                                                    
    Start 4: echo1                                                                                                                                                                                      
4/6 Test #4: echo1 ............................   Passed    0.00 sec                                                                                                                                    
    Start 5: echo2                                                                                                                                                                                      
5/6 Test #5: echo2 ............................   Passed    0.00 sec                                                                                                                                    
    Start 6: false1                                                                                                                                                                                     
6/6 Test #6: false1 ...........................   Passed    0.00 sec                                                                                                                                    

100% tests passed, 0 tests failed out of 6                                                                                                                                                              

Total Test time (real) =   0.02 sec                                                                                                                                                                     
Built target dev                                                       
```


```bash
 time ./timedrun 2 ping -c1 google.com                                                                                                                  

./timedrun 2 ping                                                                                                                                                                                       
total num: 2                                                                                                                                                                                            

newargv:  ping -c1 google.com                                                                                                                                                                           

run: 1                                                                                                                                                                                                  
PING google.com (202.124.127.245) 56(84) bytes of data.                                                                                                                                                 
64 bytes from 245.127.124.202.static.snap.net.nz (202.124.127.245): icmp_seq=1 ttl=60 time=7.88 ms                                                                                                      
--- google.com ping statistics ---                                                                                                                                                                      
1 packets transmitted, 1 received, 0% packet loss, time 0ms                                                                                                                                             
rtt min/avg/max/mdev = 7.880/7.880/7.880/0.000 ms                                                                                                                                                       
ret: 0                                                                                                                                                                                                  
run 1 time = 0.019041 seconds                                                                                                                                                                           

run: 2                                                                                                                                                                                                  
PING google.com (202.124.127.251) 56(84) bytes of data.                                                                                                                                                 
64 bytes from 251.127.124.202.static.snap.net.nz (202.124.127.251): icmp_seq=1 ttl=60 time=8.39 ms                                                                                                      
--- google.com ping statistics ---                                                                                                                                                                      
1 packets transmitted, 1 received, 0% packet loss, time 0ms                                                                                                                                             
rtt min/avg/max/mdev = 8.396/8.396/8.396/0.000 ms                                                                                                                                                       
ret: 0                                                                                                                                                                                                  
run 2 time = 0.019963 seconds                                                                                                                                                                           
Total time = 0.039315 seconds                                                                                                                                                                           

real    0m0.041s                                                                                                                                                                                        
user    0m0.000s                                                                                                                                                                                        
sys     0m0.000s                                     
```
