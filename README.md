# asciisay
Generate custom ASCII art with a message from the terminal. Inspired by cowsay

## Usage
1. Download latest binary for your system from Releases tab
2. Optionally add the binary to PATH as asciisay to use it anywhere
3. Run it:
```
./asciisay "Message here" ascii_text_file.txt
```

## ASCII art format
Make sure to put the %s where you want the message to be (so the program can format it). Here's an example:
```
------------
%s
------------
   \   ^__^
    \  (oo)\_______
       (__)\       )\/\
           ||----w |
           ||     ||
```

So, if we run
```shell
./asciisay "Hello Cow!" cow.txt
```
the result will be
```
------------
Hello Cow!
------------
   \   ^__^
    \  (oo)\_______
       (__)\       )\/\
           ||----w |
           ||     ||
```
## Notes
A message can contain up to 1024 characters, ASCII art's size can be up to 4096 characters, and the length of each line in the message is 64 characters (to break the message in lines for readablity, i.e word wrap)
