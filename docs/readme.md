# Corner Detection Challenge Judge

> Author: Dipsy ([dipsywong98](https://github.com/hkust-smartcar/Corner-Detection-Challenge/commits?author=dipsywong98))

### Spec and Flow: 

- Github page to host submission page and score
- Firebase to handle users and submission file
- Skygear for pub/sub, synchronizing client and judge (PS: If you want to go web dev, never use skygear! It sucks and forces me to learn firebase)
- Host a php script `admin.php` anywhere (but need to be windows) to listen the changes on firebase, organize the test queue, post to compile the cpp file, and run in parallel using `tasker.exe`. when finish, `admin.php` post the result to firebase and organize next file to run, and the client side update the result
- The judge system is safe since you no need to expose your ip, except the file you compiling may be a virus

### How to Host : 

1. git clone the whole project

2. Install php or xampp on your windows computer

3. Install MinGW and add it to `PATH`

4. Test whether your environment can compile C++ using php by hosting this script, where `helloworld.cpp` is a c++ hello world source code

   ```php
   <?php
   	exec("g++ helloworld.cpp", $r, $c);
   	echo $c;
   ?>
   ```

   output 0 is good and can proceed, ~~else you need to review your life, maybe making your own judge system is a better choice (?)~~

5. Get firebase id and key as well as that of skygear, and put it to `docs/config.js` Note that inside `config.js` there is one for development and one for production ~~but I am too dump to better separate them~~

6. Photos in folder `docs/sandbox/img` in bmp **bit depth 1**

7. `ans.json` contain all corners, you may get it manually using `docs/sandbox/corner.html` or generate using your executable (but need to make sure its JSON structure), and fine tune using `corner.html`

8. Host the `docs/` directory

9. Open `localhost/admin.php` on browser and don't close it, since this will shut down the judge

Note: ~~since the author is too dump (AKA dipsy),~~ the `tasker.exe` sometimes cannot check some procedure run overtime, please check manually regularly, and terminate it by task manager, good luck and happy corner detection challenge



PS: I dont want to explain more about my code since it will be easier to make a new one than understand my code