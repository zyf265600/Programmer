import { TestBed } from '@angular/core/testing';
import { ResolveFn } from '@angular/router';

import { getTopsecretResolver } from './get-topsecret.resolver';

describe('getTopsecretResolver', () => {
  const executeResolver: ResolveFn<boolean> = (...resolverParameters) => 
      TestBed.runInInjectionContext(() => getTopsecretResolver(...resolverParameters));

  beforeEach(() => {
    TestBed.configureTestingModule({});
  });

  it('should be created', () => {
    expect(executeResolver).toBeTruthy();
  });
});
