    #include<bits/stdc++.h>
    #include<unistd.h>
    using namespace std;

    void pipleine(const char* process1,const char* process2){
        int fd[2];
        pipe(fd);
        int id = fork();
        if(id != 0){ //parent process 
        close(fd[0]); // close the read end of the pipe
        dup2(fd[1], STDOUT_FILENO); // redirect std output to the write end of the pipe
        close(fd[1]); //close the write end of the pipe 

        execlp("/usr/bin/cat","cat","main.cpp",nullptr);
        cerr  <<  "failed to execute "  <<  process1  <<  endl;
        }else{
        close(fd[1]); // Close the write end of the pipe
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to the read end of the pipe
        close(fd[0]); // Close the read end of the pipe
        execlp("/usr/bin/grep","grep","hello",nullptr);
        cerr  <<"failed to execute "  <<  process2  <<endl;
        }

        }
    
    int main() {
    pipleine("cat main.cpp", "grep hello");
    return 0;
}
