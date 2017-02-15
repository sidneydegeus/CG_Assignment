define([
    'threejs',
    'orbitControls',
    'lib/FirstPersonControls',
    // initialization imports
    'initialize/scene',
    'initialize/camera',
    'initialize/controls',
    'initialize/renderer',
    //animation imports
    'animation/car_animation',
    'animation/sun_animation',
    'animation/daytime_animation'
], function($) {

    var scene, camera, renderer;
    var controls, firstPersonControls;
    var light, dirLight;

    var cars = [];
    var clock;
    var sky;
    var sun;
    var planeBox;

    clock = new THREE.Clock();
    scene = initScene();
    camera = initCamera();
    renderer = initRenderer();
    controls = initControls(camera);
    firstPersonControls = initFirstPersonControls(camera);
    initLight(scene, renderer);
    initAssets();

    function initLight(scene, renderer) {
        require(['initialize/light'], function(lightObject) {
            lightObject.initLight(scene, renderer);
            dirLight = lightObject.getDirLight();
            sky = lightObject.getSky();
        });
    }

    function initAssets() {
        require(['initialize/assets'], function(assetsObject) {
            assetsObject.initAssets(scene);
            planeBox = assetsObject.getPlaneBox();
            cars = assetsObject.getCars();
            sun = assetsObject.getSun();
            render();
        });
	}

    function render() {
        requestAnimationFrame(render);
        var delta = clock.getDelta();
        var time = new Date().getTime() * 0.0002;
        changeDayTime(time, dirLight, sky, scene, cars);
        moveSun(sun, time, delta);
        moveCar(cars, planeBox);
        // updating the scene based on controls
        controls.update();
        firstPersonControls.update( delta );
        // rendering the scene
        renderer.render(scene, camera);
    }

    // initialize the scene
	initScene();
});