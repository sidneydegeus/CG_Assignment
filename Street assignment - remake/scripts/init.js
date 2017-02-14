define([
    'threejs',
    'orbitcontrols',
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

    var scene, camera, renderer, controls;
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
    initLight(scene, renderer); // this one defines the vars clock, sky and dirlight...
    initAssets();

    // initLight function initiates the light on the scene
    function initLight(scene, renderer) {
        // add hemi lights
        //This will create a hemilight. A hemli light is used for a realistic sun
        var hemiLight = new THREE.HemisphereLight(0xffffff, 0xffffff, 0.05);
        hemiLight.color.setHSL(0.6, 1, 0.6);
        hemiLight.groundColor.setHSL(0.095, 1, 0.75);
        hemiLight.position.set(0, 500, 0);
        scene.add(hemiLight);

        // this is the Sun
        dirLight = new THREE.DirectionalLight(0xffffff, 1);
        dirLight.color.setHSL(0.1, 1, 0.95);
        dirLight.position.set(-1, 0.75, 1);
        scene.add(dirLight);
        // dirLight.shadowCameraVisible = true;
        dirLight.castShadow = true;
        dirLight.shadowMapWidth = dirLight.shadowMapHeight = 1024 * 2;
        var d = 30;
        dirLight.shadowCameraLeft = -d;
        dirLight.shadowCameraRight = d;
        dirLight.shadowCameraTop = d;
        dirLight.shadowCameraBottom = -d;

        // the magic is here - this needs to be tweaked if you change dimensions
        dirLight.shadowCameraFar = 3500;
        dirLight.shadowBias = -0.000001;
        dirLight.shadowDarkness = 0.35;
        scene.add(dirLight);
        scene.fog = new THREE.Fog(0x222233, 0, 20000);
        renderer.setClearColor(scene.fog.color, 1);

        var vertexShader = document.getElementById('vertexShader').textContent;
        var fragmentShader = document.getElementById('fragmentShader').textContent;
        var uniforms = {
            topColor: {type: "c", value: new THREE.Color(0x0077ff)},
            bottomColor: {type: "c", value: new THREE.Color(0xffffff)},
            offset: {type: "f", value: 33},
            exponent: {type: "f", value: 0.6}
        };

        //This will create the sky. It will be blue when the sun is up and black when its night
        uniforms.topColor.value.copy(hemiLight.color);
        scene.fog.color.copy(uniforms.bottomColor.value);
        var skyGeo = new THREE.SphereGeometry(50, 5, 50);
        var skyMat = new THREE.ShaderMaterial({
            vertexShader: vertexShader,
            fragmentShader: fragmentShader,
            uniforms: uniforms,
            side: THREE.BackSide
        });
        sky = new THREE.Mesh(skyGeo, skyMat);
        scene.add(sky);
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
        // rendering the scene
        renderer.render(scene, camera);
    }

    // initialize the scene
	initScene();
});