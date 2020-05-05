#include <stdio.h>
#include <bangtal.h>
#include <time.h>
#include <stdlib.h>

SceneID scene1;
TimerID timer1, timer2;

ObjectID A, B, C, D, E, F, G, H, I, J, K, L;

bool look = 1;
int num;
int check;


int Random() {
    srand(time(NULL));
    num = rand() % 5; // 수정해주기
    return num + 1;
}

int Random2() {
    srand(time(NULL));
    check = rand() % 2; // 수정해주기
    return check ;
}

void Mytimer1(int chekc) {
 
    if (check == 0) { // 이미지가 바뀜
        hideObject(F);
        showObject(G); // 뒤
        setTimer(timer1, Random());
        startTimer(timer1);
    }

    if (check == 1) {
        hideObject(G);
        showObject(F);
        setTimer(timer1, Random());
        startTimer(timer1);
        
    }
}


void timerCallback(TimerID timer) {
    if (timer == timer1) {
        Mytimer1(Random2());

    }

}



void game_init() {

    scene1 = createScene("교실", "classroom.jpg");

    A = createObject("teacher1.png");
    locateObject(A, scene1, 900, 130);
    scaleObject(A, 0.5f);
    showObject(A);


    B = createObject("student1.png");
    locateObject(B, scene1, 100, 0);
    scaleObject(B, 0.8f);
    showObject(B);

    C = createObject("student2.png");
    locateObject(C, scene1, 600, 0);
    scaleObject(C, 0.8f);
    showObject(C);

    D = createObject("student3.png");
    locateObject(D, scene1, 1100, 0);
    scaleObject(D, 0.8f);
    showObject(D);


    E = createObject("sleepingstudent2.png");
    locateObject(E, scene1, 600, 0);
    hideObject(E);


    F = createObject("teacher2.png");
    locateObject(F, scene1, 900, 130);
    scaleObject(F, 0.5f);
    hideObject(F);

    G = createObject("teacher3.png");
    locateObject(G, scene1, 900, 130);
    scaleObject(G, 0.5f);
    hideObject(G);


    
    H = createObject("play.png");
    locateObject(H, scene1, 640, 100);
    hideObject(H);

    I = createObject("end.png");
    locateObject(I, scene1, 640, 100);
    showObject(I);

    J = createObject("start.png");
    locateObject(J, scene1, 640, 150);
    showObject(J);

    K = createObject("sleepButton.png");
    locateObject(K, scene1, 350, 0);
    scaleObject(K, 0.5f);
    hideObject(K);


    L = createObject("getupButton.png");
    locateObject(L, scene1, 850, 0);
    scaleObject(L, 0.5f);
    hideObject(L);




}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    //endButton버튼 누르면 게임종류
    if (object == I) {
        endGame();
    }
    //스타트 버튼을 누르면 endButton 사라지고 플레이 버튼 생긴다
    else if (object == J) {
        hideObject(I);
        hideObject(J);
        showObject(H);
    }
    //플레이 버튼을 누르면 교수가 교수1에세 교수 2 교수 3을 반복적으로 한다. 여기서 학생을 클릭시 학생이 자다 안자다가 한다. 타이머 작동된다 또 sleep버튼이랑 getup 버튼이 생김
    // 조건에 따라 hide했다 slow 했다 하기로 a가 하이드면 b가 쇼 하는 거로
    else if (object == H) {
        Mytimer1(Random2());
   
    
        hideObject(H);
        showObject(K);
        showObject(L);
        //teacher1이 teacher2로 바뀜
        hideObject(A);
        showObject(F);  







    }


    //sleep Button을 클릭시 student2 잠자고 get up을 클릭시 일어나기
    else if (object == K) { //sleepbutton
        hideObject(C);
        showObject(E);
        showObject(N);

  

        //여기서 teacher3이랑 겹쳐질시 하트 깎임

    }

    //getupButton 클릭시 일어나기
    else if (object == L) {
        hideObject(E);
        showObject(C);
        showObject(M);
        
        if (check ==0) {
            showMessage("게임오버");
        }


    }
    //그냥 사람 클릭해도 자다가 안자다가 변함
    else if (object == C) {
        hideObject(C);
        showObject(E);
        showObject(N);
    }
    else if (object == E) {
        hideObject(E);
        showObject(C);
        showObject(M);
    }
    


}



int main() {
    setTimerCallback(timerCallback);
    setMouseCallback(mouseCallback);
    game_init();
    timer1 = createTimer(0.0f);
    showTimer(timer1);
    startGame(scene1);

}