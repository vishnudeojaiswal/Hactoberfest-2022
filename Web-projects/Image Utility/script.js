const fileInput = document.querySelector("#imgInput")
const canvas = document.querySelector("#canvas")

const canvasCtx = canvas.getContext("2d")

const brightnessInput = document.querySelector("#brightness")
const saturationInput = document.querySelector("#saturation")
const blurInput = document.querySelector("#blur")
const inversionInput = document.querySelector("#inversion")
const grayscaleInput = document.querySelector("#grayscale")
const reset = document.querySelector("#reset");

const settings = {};

let image = null;

const resetSettings = () => {
    settings.brightness = "100";
    settings.blur = "0";
    settings.saturation = "100";
    settings.inversion = "0";
    settings.grayscale = "0"

    brightnessInput.value = settings.brightness;
    blurInput.value = settings.blur;
    saturationInput.value = settings.saturation;
    inversionInput.value = settings.inversion;
grayscaleInput.value = settings.grayscale;
}



const genFilter = () => {
    const { brightness, saturation, inversion, blur , grayscale} = settings;
    return `brightness(${brightness}%) saturate(${saturation}%) blur(${blur}px) invert(${inversion}%) grayscale(${grayscale}%)`;
}

const renderImage = async () => {
    canvas.width = image.width;
    canvas.height = image.height;
    canvasCtx.filter = genFilter();
    
    canvasCtx.drawImage(image, 0, 0);
}

const updateSettings = (key, value) => {
    if (!image) {
        return;
    }
    settings[key] = value;
    renderImage();
}

brightnessInput.addEventListener("change", () => updateSettings("brightness", brightnessInput.value));
blurInput.addEventListener("change", () => updateSettings("blur", blurInput.value));
saturationInput.addEventListener("change", () => updateSettings("saturation", saturationInput.value));
inversionInput.addEventListener("change", () => updateSettings("inversion", inversionInput.value));
grayscaleInput.addEventListener("change", () => updateSettings("grayscale", grayscaleInput.value));


fileInput.addEventListener("change", () => {
    image = new Image();

    image.addEventListener("load", () => {
        resetSettings();
        renderImage()
    })

    // as file input tag can accepr multiple files , se wee need to choose the first one so 0 is there
    image.src = URL.createObjectURL(fileInput.files[0]);
    // console.log(image.src);  

})

reset.addEventListener("click", ()=>
{
    resetSettings();
    renderImage();
});

resetSettings();


