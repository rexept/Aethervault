<img src="assets/Aethervault-logot.svg" alt="Aethervault" width="100%" />

---

This is currently in the alpha phase and will be coming soon...\
This currently only works Linux

# Build Instructions (developement)
Create a build directory and cd into it:
```
mkdir build
cd build
```

Run generation command (the flag is for Neovim to have proper linking):
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
```

Now, just run `make` inside the build directory and run the `Aethervault` executable!

# What it does
Aethervault is a **Contact Manager**

---
# To-Do
- [ ] Save to SQL database
- [ ] Encryption
- [ ] Make new layout
- [ ] Add search bar
