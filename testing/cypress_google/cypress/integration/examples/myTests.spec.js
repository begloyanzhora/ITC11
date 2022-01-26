/// <reference types="Cypress" />

describe('MyTest', () => {
  it('Verify the result', () => {
    cy.visit('https://www.google.com/')
    cy.get('.gLFyf.gsfi').type('testing{enter}')
    cy.get('.g:first').should('contain.text', 'testing')
  })
})