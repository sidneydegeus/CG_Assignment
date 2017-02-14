/*define(['threejs', 'orbitcontrols'], function($) {

    function initControls(camera) {

    }

    return {
        getControls: function (camera) {
            return initControls(camera);
        }
    };
});*/

function initControls(camera) {
    var controls = new THREE.OrbitControls(camera);
    controls.noKeys = true;
    return controls;
}