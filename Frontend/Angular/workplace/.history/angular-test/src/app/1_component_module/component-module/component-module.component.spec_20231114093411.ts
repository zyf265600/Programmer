import { TestBed } from '@angular/core/testing';
import { Component } from '@angular/core';
import { ComponentModuleComponent } from './component-module.component';

describe('ComponentModuleComponent', () => {
  let usersService: ComponentModuleComponent; // Add this

  beforeEach(() => {
    TestBed.configureTestingModule({
      providers: [ComponentModuleComponent]
    });

    usersService = TestBed.get(UsersService); // Add this
  });

  it('should be created', () => { // Remove inject()
    expect(usersService).toBeTruthy();
  });
});