Instructions for directing Arduino IDE to libraries folder in Git directory:

1. in arduino IDE navigate to:

    File > Preferences (Ctrl+Comma)
   
2. Change Sketchbook location to the location of the Git repository
    note: this will be the directory that has the "libraries" inside it, not the libraries folder itself.
    for me the new file path is C:\Users\my name\Documents\Arduino\ENEL400
    
Now Arduino IDE will look for libraries in the folder that is updated with the git repository.

Put all libraries that are needed in this folder.
