var run_dev = false

if(run_dev===true){
  var firebase_config = {
    apiKey: "AIzaSyCGW3Ux9K0u9ECRcYl2i-mrH26hmBeRrVE",
    authDomain: "corner-ch-dev.firebaseapp.com",
    databaseURL: "https://corner-ch-dev.firebaseio.com",
    projectId: "corner-ch-dev",
    storageBucket: "gs://corner-ch-dev.appspot.com",
    messagingSenderId: "753407307943"
  }

  var skygear_config = {
    'endPoint': 'https://cornerchdev.skygeario.com/', // trailing slash is required
    'apiKey': 'd4f2c124ad7843f4af8f4cb7b51b9db7',
  }
}
else{
  var firebase_config = {
    apiKey: "AIzaSyDeXslekRSxKlQzvdS3b908i18s1Ztg5ak",
    authDomain: "corner-ch.firebaseapp.com",
    databaseURL: "https://corner-ch.firebaseio.com",
    projectId: "corner-ch",
    storageBucket: "gs://corner-ch.appspot.com",
    messagingSenderId: "202391887409"
  }

  var skygear_config = {
    'endPoint': 'https://cornerch.skygeario.com/', // trailing slash is required
    'apiKey': '93e92fb17bce4768820d623c71ca7b6d',
  }
}

