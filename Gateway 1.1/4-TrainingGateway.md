# USACO Training Gateway
https://train.usaco.org/

### Six Chapters
- Chapter 1: Getting Started
- Chapter 2: Bigger Challenges
- Chapter 3: Techniques more subtle
- Chapter 4: Advanced algorithms and difficult drills
- Chapter 5: Serious challenges
- Chapter 6: Contest Practice

##### You have to solve all problems in previous chapter to be able to see next one. 

### First Submission
- All submission must have a comment block at top with following contents
  - LANG:
  - TASK:
  - These 2 lines should not contain any other characters, including '*'
- All input/output files are named exactly after TASK keyword:
  - **<task name\>.in**
  - **<task name\>.out**
  - Input file will always have the last line with an '\\n' only
  - Output file should also produce an '\\n' at the end as the last finishing line


##### Special notes for Java programmer:
- USACO does not expect any "package" line on top of your main class. So you have to drop it.

---
File I/O
---

#### Java
```java
Scanner sc = new Scanner(new File("test.in"));
int x = sc.nextInt();
int y = sc.nextInt();

FileWriter fw = new FileWriter("test.out");
fw.write( (x+y) + "\n" );
fw.close();
```

#### Python
```python
with open('test.in') as fin, open('test.out', 'w') as fout:
    fout.write ('%s\n' % sum(map(int, fin.readline().split())))
```

#### C++
```cpp
ifstream fin ("test.in");
int a, b;
fin >> a >> b;

ofstream fout ("test.out");
fout << a+b << endl;
```

---
Running Code Online
---
- [Replit](https://repl.it/)
- [Judge0](https://ide.judge0.com)
- [IDE1](https://ideone.com)
- [CSA Academy](https://csacademy.com/workspace/)
- [Goorm](https://ide.goorm.io/)

You can also share code with [pastebin](https://pastebin.com) or [hastebin](https://hastebin.com).

---
Running Code Locally
---

- Java
 - JetBrains - [IntelliJ IDEA Community](https://www.jetbrains.com/idea/)
 - Eclipse Foundation - [Eclipse](https://www.eclipse.org/eclipseide/)
 - King's College London - [BlueJ](https://bluej.org/)
- C/C++
 - Microsoft - [Visual Studio](https://visualstudio.microsoft.com/zh-hans/free-developer-offers/)
