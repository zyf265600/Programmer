import { TestBed } from '@angular/core/testing';
import { CanActivateChildFn } from '@angular/router';

import { topsecretGuard } from './topsecret.guard';

describe('topsecretGuard', () => {
  const executeGuard: CanActivateChildFn = (...guardParameters) => 
      TestBed.runInInjectionContext(() => topsecretGuard(...guardParameters));

  beforeEach(() => {
    TestBed.configureTestingModule({});
  });

  it('should be created', () => {
    expect(executeGuard).toBeTruthy();
  });
});
