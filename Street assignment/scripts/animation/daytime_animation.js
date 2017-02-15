// changeDayTime function
function changeDayTime(time, dirLight, sky, scene, cars) {
    // var time = 2.1;
    var nsin = Math.sin(time);
    var ncos = Math.cos(time);

    // set the sun
    //An if statement that will make it cycles to day/night. This will be the sun statement.
    //The sky will be set to blue and the carLights will change to yellow
    dirLight.position.set( 1500*nsin, 2000*nsin, 2000*ncos);
    if (nsin > 0.2 ) { // day
        sky.material.uniforms.topColor.value.setRGB(0.25,0.55,1);
        sky.material.uniforms.bottomColor.value.setRGB(1,1,1);
        var f = 1;
        dirLight.intensity = f;
        dirLight.shadowDarkness = f*0.7;
    }
    else if (nsin < 0.2 && nsin > 0.0 ) {
        var f = nsin/0.2;
        dirLight.intensity = f;
        dirLight.shadowDarkness = f*0.7;
        sky.material.uniforms.topColor.value.setRGB(0.25*f,0.55*f,1*f);
        sky.material.uniforms.bottomColor.value.setRGB(1*f, 1*f, 1*f);
    }

    //This is the night statement. The sky will be set to black and the carLights to grey
    else { // night
        var f = 0;
        dirLight.intensity = f;
        dirLight.shadowDarkness = f*0.7;
        sky.material.uniforms.topColor.value.setRGB(0,0,0);
        sky.material.uniforms.bottomColor.value.setRGB(0,0,0);
    }
}