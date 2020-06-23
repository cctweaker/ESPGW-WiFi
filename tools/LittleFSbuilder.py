Import("env")
print("Using mklittlefs.exe from https://github.com/earlephilhower/mklittlefs")
env.Replace( MKSPIFFSTOOL=env.get("PROJECT_DIR") + "/tools/mklittlefs.exe")