/* inicializando o modal */  
const linkEL = document.querySelector('link');
linkEL.addEventListener('click', abreModal);
/* deixando visivel */  
function abreModal(e){
    const modalEl =document.querySelector('.modal');
    modalEl.classList.add('visivel');
}