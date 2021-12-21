## 📰 Description
Provide 𝑘𝑖𝑟𝑘 with an emergency transporter feature. This will pull him from a planet immediately if he is in danger

## :dart: Tasks to accomplish   
Modify 𝑘𝑖𝑟𝑘2.𝑐 (creating 𝑘𝑖𝑟𝑘3.𝑐) so that he will respond to the arrival of a signal of type 𝑆𝐼𝐺𝑇𝐸𝑅𝑀.

## 🔑 Hints
1. Transportation can be achieved by printing a message in 𝐾𝑖𝑟𝑘’𝑠 signal handler.  
2. You may not use the printf() function as it is not async-signal-safe. You may check the man page of signal-safety.
3. Use the examples in Beej’s guide to help you make this change.  
