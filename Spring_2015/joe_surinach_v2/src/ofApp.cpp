#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    oscRMS.setup(9001);


    movementNumber = 0;
    ofSetCircleResolution(180);
    ofSetCurveResolution(180);
    
//    angela.setup();
//    kai.setup();
//    santi.setup();
    
    oscFFT.setup(9002);
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    oscRMS.update();
//    oscFFT.update();
    
    //========== MOVEMENT UPDATE METHODS ===============
    switch (movementNumber) {
        case 1:
            angela.update(oscFFT.chan2_fft);
            break;
        case 2:
            santi.update(oscFFT.chan2_fft);
            break;
        case 3:
            kai.update(oscRMS.receivedRms);
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        default:
            break;
    }
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}


//--------------------------------------------------------------
void ofApp::draw(){
    //========== MOVEMENT DRAW METHODS ===============
    switch (movementNumber) {
        case 1:
            angela.draw();
            break;
        case 2:
            santi.draw();
            break;
        case 3:
            kai.draw();
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_RIGHT){
        movementNumber++;
        if(movementNumber > 2)
            movementNumber = 2;
        cout << movementNumber << endl;
        
        if(movementNumber == 2)
            santi.setup();
        if(movementNumber == 3)
            cout << "setup movement 3" <<endl;
        if(movementNumber == 4)
            cout << "setup movement 4" <<endl;
        if(movementNumber == 5)
            cout << "setup movement 5" <<endl;
        if(movementNumber == 6)
            cout << "setup movement 6" <<endl;

    } else if (key == OF_KEY_LEFT){
        movementNumber--;
        if(movementNumber < 1)
            movementNumber = 1;
        cout << movementNumber << endl;
    }
    
    else {
        switch (movementNumber){
            case 1:
                angela.keyPressed(key);
                break;
            case 2:
                santi.keyPressed(key);
                break;
            case 3:
                kai.keyPressed(key);
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            default:
                break;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
    switch (movementNumber){
        case 1:
            kai.mousePressed(x,y,button);
            break;
        case 2:
            santi.mousePressed(x,y,button);
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
