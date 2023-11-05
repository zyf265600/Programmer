import { TestBed } from '@angular/core/testing';

import { AuthcheckService } from './authcheck.service';

describe('AuthcheckService', () => {
  let service: AuthcheckService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(AuthcheckService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
