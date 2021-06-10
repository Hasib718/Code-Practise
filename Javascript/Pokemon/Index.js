const container = document.querySelector('#container')

for (let i=1; i<899; i++) {
    const newImg = document.createElement('img')
    const label = document.createElement('span')
    const pokemon = document.createElement('div')

    pokemon.classList.add('pokemon')
    label.innerText = `#${i}`
    newImg.src = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${i}.png`
    
    newImg.addEventListener('mouseover', () => {
        newImg.height = 200
        newImg.width = 200
    })
    
    newImg.addEventListener('mouseout', () => {
        newImg.height = 96
        newImg.width = 96
    })

    pokemon.appendChild(newImg)
    pokemon.appendChild(label)
    container.appendChild(pokemon)
}
