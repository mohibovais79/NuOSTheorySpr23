                                         Mohib Ahmed K213006
0. install the following commands
• sudo apt-get install gcc 
• sudo apt-get install libncurses5-dev
• sudo apt-get install bison
• sudo apt-get install flex
• sudo apt install make
• sudo apt-get install libssl-dev
• sudo apt-get install libelf-dev
• sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) main universe"
• sudo apt-get update • sudo apt-get upgrade

1. Go to linux folder. Create new folder name hello

![image](https://user-images.githubusercontent.com/89134017/220843632-7013334f-ceb6-4a1a-8d92-ea978aee5963.png)

2.create a new file name hello.c and write the following code
  . #include <linux/kernel> : this library is for calling linux system calls
  . Amslinkage: arguments for this function will be on the stack instead of the CPU registers.
  . printk: To print in kernel's log file
  

![image](https://user-images.githubusercontent.com/89134017/220843742-00a2cf93-c87c-4d62-ac38-46c3857f6a8f.png)

create a file with name Makefile

![image](https://user-images.githubusercontent.com/89134017/220843771-1c212b86-a46c-4864-957a-43cdcccbc40d.png)
3. Add this new code system table file

![image](https://user-images.githubusercontent.com/89134017/220843804-caa0d6ae-2990-4bdc-9ae4-3adc7a8cf709.png)

4. add the function protoype in header file


  ![image](https://user-images.githubusercontent.com/89134017/220843831-e9a69d10-fad8-4450-adfb-f9f622d70d0e.png)
  
5. Change the version of kernel to your roll no
  
  
![image](https://user-images.githubusercontent.com/89134017/220843857-9e8d96e1-e492-4da0-94e3-2f395813d881.png)
6. Create a config file


![image](https://user-images.githubusercontent.com/89134017/220843886-9da89989-f29b-4f7c-ad55-3c872593e117.png)

7. Clean and compile the kernel 
 
![image](https://user-images.githubusercontent.com/89134017/220843903-b2e48fbd-d524-467a-82ed-f7a4fa675553.png)
8. Making sure all steps are performed


![image](https://user-images.githubusercontent.com/89134017/220843916-7d954d5d-60d3-4bdb-a76b-78a9b0f8324e.png)


![image](https://user-images.githubusercontent.com/89134017/220843931-9c421750-34f9-4f17-a37c-c7da1ec4bc53.png)


![image](https://user-images.githubusercontent.com/89134017/220843947-71114cba-2693-4eb0-810a-cc1619fee184.png)


![image](https://user-images.githubusercontent.com/89134017/220843967-e18a11f7-fd3b-4cee-846f-fff1b7ee42db.png)

9. you can our grub window has sucessfully loaded


![image](https://user-images.githubusercontent.com/89134017/220843988-c47b12f7-9654-472a-b2a2-57fc639944d0.png)

9. Hello world and kernel version is displayed on screen successfuly

![image](https://user-images.githubusercontent.com/89134017/220844021-b556dc97-734e-44c5-ad58-caf11a77d7da.png)


