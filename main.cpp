    #include<bits/stdc++.h>
    #include<unistd.h>
    using namespace std;

    void pipleine(const char* process1,const char* process2){
        int fd[2];
        pipe(fd);
        if(fork()!= 0){ //parent process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("/bin/cat","cat","main.cpp",nullptr);
        cerr<<"failed to execute "<<process1<<endl;
        }else{
        close(fd[1]);
        dup2(fd[0], STDOUT_FILENO);
        close(fd[0]);
        execlp("user/bin/grep","grep","hello",nullptr);
        cerr<<"failed to execute "<<process2<<endl;
        }

        }
    
    int main() {
    pipleine("cat main.cpp", "grep hello");
    return 0;
}
