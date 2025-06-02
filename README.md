<img src="assets/Aethervault-logot.svg" alt="Aethervault" width="100%" />

---

Aethervault is a **CRM**\
This is currently in the development phase and will be coming soon...

# Build Instructions (development)

After following above instructions create a build directory and cd into it:
```
mkdir build
cd build
```

Run generation command (the flag is for Neovim to have proper linking):
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
```

Now, just run `make` inside the build directory and run the `Aethervault` executable!
bun
---
# To-Do
- [x] Save to SQL database
- [ ] Importing via various file types 
- [ ] Encryption
- [ ] Make new layout
- [ ] Add search bar
