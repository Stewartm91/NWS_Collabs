//
//  oscFFT.cpp
//  surinach_v2
//
//  Created by performer on 3/28/15.
//
//

#include "oscFFT.h"


//-----------------------------------------------------------
void surinachOscFft::setup(){
    
    cout << "hit surinach OSC setup" << endl;
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    
    
    nBandsToUse = 2048;
    //    receivedRms = new float[nBandsToUse];
    chan1_fft = new float[nBandsToUse];
    chan2_fft = new float[nBandsToUse];
    
    chan1_amp = 0;
    chan2_amp = 0;
    chan3_amp = 0;
    chan4_amp = 0;
    
    for (int i = 0; i < nBandsToUse; i++){
        //        receivedRms[i] = 0;
        chan1_fft[i] = 0;
        chan2_fft[i] = 0;
        chan1_fft_bands[i] = 0;
    }
}

//-----------------------------------------------------------
void surinachOscFft::update(){
    
//    cout << sizeof(chan1_fft)<<endl;
    
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/channel_01/FFT"){ //FFT
            int index = m.getArgAsInt32(0);
            float val = m.getArgAsFloat(1);
            chan1_fft[index] = val;
            chan1_fft_bands[index] = val;
            //cout << "recvd: " << index << " :\t"<<val<<endl;
        }
        
        else if(m.getAddress() == "/channel_02/FFT"){ //FFT
            int index = m.getArgAsInt32(0);
            float val = m.getArgAsFloat(1);
            chan2_fft[index] = val;
            //cout << "recvd chan 2: " << index << " :\t"<<val<<endl;
        }
        
        else if(m.getAddress() == "/channel_01/AMP"){ //AMP
            float val = m.getArgAsFloat(0);
            chan1_amp = val;
            //cout << "recvd chan1 amp: " << " :\t"<<val<<endl;
        }
        else if(m.getAddress() == "/channel_02/AMP"){ //AMP
            float val = m.getArgAsFloat(0);
            chan2_amp = val;
            //cout << "recvd chan2 amp: " << " :\t"<<val<<endl;
        }
        else if(m.getAddress() == "/channel_03/AMP"){ //AMP
            float val = m.getArgAsFloat(0);
            chan3_amp = val;
            //cout << "recvd chan3 amp: " << " :\t"<<val<<endl;
        }
        else if(m.getAddress() == "/channel_04/AMP"){ //AMP
            float val = m.getArgAsFloat(0);
            chan3_amp = val;
            //cout << "recvd chan4 amp: " << " :\t"<<val<<endl;
        }
        
        else {
            string msg_string;
            msg_string = m.getAddress();
            cout << "unrecognized message " << msg_string << endl;
        }
    }
}